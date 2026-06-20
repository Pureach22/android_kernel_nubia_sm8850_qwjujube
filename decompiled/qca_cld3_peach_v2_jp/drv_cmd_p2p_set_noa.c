__int64 __fastcall drv_cmd_p2p_set_noa(__int64 a1, int a2, char *s)
{
  return hdd_set_p2p_noa(*(_QWORD *)(*(_QWORD *)a1 + 32LL), s);
}
