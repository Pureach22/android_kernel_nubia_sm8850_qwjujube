__int64 hdd_select_queue()
{
  return ((__int64 (*)(void))hdd_wmm_select_queue)();
}
