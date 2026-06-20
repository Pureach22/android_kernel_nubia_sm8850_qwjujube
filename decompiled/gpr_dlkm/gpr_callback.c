__int64 __fastcall gpr_callback(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 v3; // x22
  const void *v4; // x20
  unsigned int v6; // w8
  unsigned int v7; // w19
  _DWORD *v8; // x19
  __int64 v9; // x21
  _DWORD *v10; // x19
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x24
  __int64 v14; // x21
  _DWORD *v15; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( a3 <= 0x17 )
  {
    v4 = a2;
    if ( (unsigned int)__ratelimit(&gpr_callback__rs, "gpr_callback") )
      dev_err(*(_QWORD *)(v3 + 8), "GPR: Improper gpr pkt received:%p %d\n", v4, a3);
    return 4294967274LL;
  }
  v6 = *a2;
  v7 = (*a2 >> 2) & 0x3C;
  if ( v7 <= 0x17 )
  {
    if ( (unsigned int)__ratelimit(&gpr_callback__rs_44, "gpr_callback") )
      dev_err(*(_QWORD *)(v3 + 8), "GPR: Wrong hdr size:%d\n", v7);
    return 4294967274LL;
  }
  if ( ((v6 >> 11) & 0x1FFF) < 3 || a3 != (unsigned __int16)(v6 >> 8) )
  {
    if ( (unsigned int)__ratelimit(&gpr_callback__rs_46, "gpr_callback") )
      dev_err(*(_QWORD *)(v3 + 8), "GPR: Wrong packet size\n");
    return 4294967274LL;
  }
  if ( a2[5] == 50335744 )
  {
    v8 = a2;
    pm_wakeup_ws_event(*(_QWORD *)(gpr_priv + 96), 200, 1);
    a2 = v8;
  }
  v9 = *((unsigned __int16 *)a2 + 6);
  v10 = a2;
  v11 = raw_spin_lock_irqsave(v3 + 24);
  v12 = idr_find(v3 + 32, v9);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 136)) == 0 )
  {
    v12 = idr_find(v3 + 32, 23);
    if ( !v12 || (v13 = *(_QWORD *)(v12 + 136)) == 0 )
    {
      raw_spin_unlock_irqrestore(v3 + 24, v11);
      goto LABEL_23;
    }
  }
  v14 = v12;
  raw_spin_unlock_irqrestore(v3 + 24, v11);
  if ( v13 == 24 )
  {
LABEL_23:
    if ( (unsigned int)__ratelimit(&gpr_callback__rs_48, "gpr_callback") )
      dev_err(*(_QWORD *)(v3 + 8), "GPR: service is not registered\n");
    if ( v10[5] == 50335744 )
      _pm_relax(*(_QWORD *)(gpr_priv + 96));
    return 4294967274LL;
  }
  v15 = *(_DWORD **)(v13 - 8);
  if ( *(v15 - 1) != -573620832 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _DWORD *))v15)(v14, v10);
  return 0;
}
