__int64 __fastcall osif_send_twt_delete_cmd(__int64 a1, int *a2, unsigned __int8 a3, char a4)
{
  ucfg_twt_set_work_params(a1, a2, a3, a4, 1);
  return queue_work_on(32, system_wq, a1 + 1368);
}
