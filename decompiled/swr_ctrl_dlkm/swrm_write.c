__int64 __fastcall swrm_write(__int64 a1, unsigned __int8 a2, unsigned __int16 a3, unsigned __int8 *a4)
{
  __int64 v5; // x19
  int v6; // w22
  int v9; // w25
  int v10; // w3
  char v11; // w8
  __int64 v12; // x0
  __int64 v13; // x19

  if ( !a1 || (v5 = *(_QWORD *)(a1 + 152)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&swrm_write__rs, "swrm_write") )
      dev_err(a1, "%s: swrm is NULL\n", "swrm_write");
    return 4294967274LL;
  }
  if ( !a2 )
  {
    if ( (unsigned int)__ratelimit(&swrm_write__rs_138, "swrm_write") )
      dev_err(a1, "%s: invalid slave dev num\n", "swrm_write");
    return 4294967274LL;
  }
  v6 = *a4;
  mutex_lock(v5 + 8736);
  v9 = *(unsigned __int8 *)(v5 + 15748);
  mutex_unlock(v5 + 8736);
  if ( v9 != 1 )
    return 0;
  _pm_runtime_resume(*(_QWORD *)(v5 + 8512), 4);
  if ( *(_BYTE *)(v5 + 15750) == 1 )
    swrm_runtime_resume(*(_QWORD *)(v5 + 8512));
  v10 = *(unsigned __int8 *)(v5 + 9050);
  v11 = (v10 + 1) & 0xF;
  if ( v10 == 14 )
    v11 = 0;
  *(_BYTE *)(v5 + 9050) = v11;
  swrm_cmd_fifo_wr_cmd(v5, v6, a2, v10, a3);
  v12 = _pm_runtime_suspend(*(_QWORD *)(v5 + 8512), 13);
  v13 = *(_QWORD *)(v5 + 8512);
  *(_QWORD *)(v13 + 520) = ktime_get_mono_fast_ns(v12);
  return 0;
}
