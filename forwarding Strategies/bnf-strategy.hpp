/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014-2019,  Regents of the University of California,
 *                           Arizona Board of Regents,
 *                           Colorado State University,
 *                           University Pierre & Marie Curie, Sorbonne University,
 *                           Washington University in St. Louis,
 *                           Beijing Institute of Technology,
 *                           The University of Memphis.
 *
 * This file is part of NFD (Named Data Networking Forwarding Daemon).
 * See AUTHORS.md for complete list of NFD authors and contributors.
 *
 * NFD is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NFD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NFD, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NFD_DAEMON_FW_NATIVE_VNDN_STRATEGY_HPP
#define NFD_DAEMON_FW_NATIVE_VNDN_STRATEGY_HPP

#include "strategy.hpp"
#include "algorithm.hpp"
#include "process-nack-traits.hpp"
#include "forwarder.hpp"


/*
This forwarding strategy is built based on paper "VANET via Named Data Networking" by Giulio Grassi, 2014
it is called Vanilla VNDN
*/

namespace nfd {
namespace fw {



/** \brief a forwarding strategy that forwards Interest to all FIB nexthops
 *
 *  \note This strategy is not EndpointId-aware.
 */
class FloodingVndnStrategy : public Strategy
                         , public ProcessNackTraits<FloodingVndnStrategy>
{
public:
  FloodingVndnStrategy(Forwarder& forwarder, const Name& name = getStrategyName());

  virtual
  ~FloodingVndnStrategy() override;

  void
  afterReceiveInterest(const FaceEndpoint& ingress, const Interest& interest,
                       const shared_ptr<pit::Entry>& pitEntry) override;
  
  void
  afterReceiveNack(const FaceEndpoint& ingress, const lp::Nack& nack,
                                 const shared_ptr<pit::Entry>& pitEntry) override;
  
  static const Name&
  getStrategyName();

 
private:
friend ProcessNackTraits<FloodingVndnStrategy>;
friend class Forwarder;
  


ns3::Time m_retxTime;

  
  
};

} // namespace fw
} // namespace nfd

#endif // NFD_DAEMON_FW_MULTICAST_STRATEGY_HPP
