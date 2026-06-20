__int64 __fastcall sde_connector_prepare_commit(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 v3; // x20
  unsigned int v4; // w21
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 result; // x0
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned int v9; // w19
  void *v10; // x0
  int v11[2]; // [xsp+10h] [xbp-30h]

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v10 = &unk_215A31;
LABEL_22:
    printk(v10, "sde_connector_prepare_commit");
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( !*(_QWORD *)(a1 + 2760) )
  {
    v10 = &unk_249B41;
    goto LABEL_22;
  }
  v2 = *(__int64 (**)(void))(a1 + 3152);
  if ( !v2 )
  {
LABEL_12:
    result = 0;
    goto LABEL_23;
  }
  v3 = *(_QWORD *)(a1 + 2512);
  *(_QWORD *)v11 = 0;
  if ( *(_BYTE *)(a1 + 4680) == 1 )
  {
    LOBYTE(v11[1]) = 1;
    v11[0] = *(_DWORD *)(a1 + 4676);
  }
  if ( *((_DWORD *)v2 - 1) != -987377525 )
    __break(0x8228u);
  v4 = v2();
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_connector_prepare_commit",
    1663,
    -1,
    *(_DWORD *)(a1 + 64),
    v11[0],
    LOBYTE(v11[1]),
    v4,
    239);
  v5 = *(_QWORD *)(a1 + 2512);
  if ( !v5 )
    goto LABEL_14;
  v6 = *(_QWORD *)(v5 + 8);
  if ( !v6 )
  {
    LODWORD(v5) = 0;
LABEL_14:
    result = v4;
    goto LABEL_15;
  }
  LODWORD(v5) = sde_crtc_get_disp_op(v6);
  result = v4;
  if ( (unsigned int)v5 >= 3 )
  {
    __break(0x5512u);
    goto LABEL_12;
  }
LABEL_15:
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8LL * (unsigned int)v5 + 5336);
  if ( v8 )
  {
    if ( *((_DWORD *)v8 - 1) != 350832056 )
      __break(0x8228u);
    result = v8(a1, v3);
    if ( (_DWORD)result )
    {
      v9 = result;
      printk(&unk_2249F3, "sde_connector_prepare_commit");
      result = v9;
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
