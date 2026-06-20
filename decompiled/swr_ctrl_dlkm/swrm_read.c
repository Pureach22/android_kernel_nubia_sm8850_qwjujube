__int64 __fastcall swrm_read(__int64 a1, unsigned int a2, unsigned int a3, _BYTE *a4, unsigned int a5)
{
  __int64 v6; // x19
  int v11; // w26
  __int64 v12; // x3
  char v13; // w8
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 mono_fast_ns; // x8
  __int64 result; // x0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v6 = *(_QWORD *)(a1 + 152), v18 = 0, !v6) )
  {
    if ( (unsigned int)__ratelimit(&swrm_read__rs, "swrm_read") )
      dev_err(a1, "%s: swrm is NULL\n", "swrm_read");
    goto LABEL_12;
  }
  if ( !(_BYTE)a2 )
  {
    if ( (unsigned int)__ratelimit(&swrm_read__rs_128, "swrm_read") )
      dev_err(a1, "%s: invalid slave dev num\n", "swrm_read");
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  mutex_lock(v6 + 8736);
  v11 = *(unsigned __int8 *)(v6 + 15748);
  mutex_unlock(v6 + 8736);
  if ( v11 == 1 )
  {
    _pm_runtime_resume(*(_QWORD *)(v6 + 8512), 4);
    if ( *(_BYTE *)(v6 + 15750) == 1 )
      swrm_runtime_resume(*(_QWORD *)(v6 + 8512));
    v12 = *(unsigned __int8 *)(v6 + 9050);
    v13 = (v12 + 1) & 0xF;
    if ( (_DWORD)v12 == 14 )
      v13 = 0;
    *(_BYTE *)(v6 + 9050) = v13;
    swrm_cmd_fifo_rd_cmd(v6, &v18, a2, v12, a3, a5);
    *a4 = v18;
    v14 = _pm_runtime_suspend(*(_QWORD *)(v6 + 8512), 13);
    v15 = *(_QWORD *)(v6 + 8512);
    mono_fast_ns = ktime_get_mono_fast_ns(v14);
    result = 0;
    *(_QWORD *)(v15 + 520) = mono_fast_ns;
  }
  else
  {
    result = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
