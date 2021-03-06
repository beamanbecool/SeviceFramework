//
// Created by Shinan on 2019/1/22.
//

#ifndef SEVICEFRAMEWORK_NETSERVICE_H
#define SEVICEFRAMEWORK_NETSERVICE_H

#include <multi-threading/InteractiveTask.h>
#include "NetWorkService.h"
class TcpServer;

class NetAcceptService : public InteractiveTask
{
public:
//  NetAcceptService(const string &name, const SpEventReactor &spEventReactor);
  NetAcceptService(const string &name, const SpEventReactor &spEventReactor, TcpServer &tcpServer);
  virtual ~NetAcceptService();

private:
  void onStart() final ;
  void onStop() final ;
  void onMessage(const shared_ptr<Message> &spMessage) final ;
public:
  void __onAccept(int fd);

public:
  vector<shared_ptr<NetWorkService>> vecSpWorkService_;

private:
  TcpServer &tcpServer_;
  int curServiceIndex_ = 0;
  int _nextServiceIndex();
};

#endif //SEVICEFRAMEWORK_NETSERVICE_H
