__int64 __fastcall tgt_spectral_register_to_dbr(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  _QWORD *v11; // x20
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  void (__fastcall *v14)(_QWORD); // x8
  _DWORD *v15; // x8
  __int64 v16; // x0
  void (__fastcall *v17)(_QWORD); // x8
  __int64 result; // x0
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 80);
  v19 = 0x100000002LL;
  if ( v10 && (v11 = *(_QWORD **)(v10 + 2128)) != nullptr )
  {
    v12 = (__int64 (__fastcall *)(__int64, __int64))v11[82];
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -1102235987 )
        __break(0x8228u);
      if ( (v12(a1, a2) & 1) != 0 )
      {
        v14 = (void (__fastcall *)(_QWORD))v11[84];
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != -2099273483 )
            __break(0x8228u);
          v14(a1);
        }
        v15 = (_DWORD *)v11[220];
        v16 = a1;
        if ( v15 )
        {
          if ( *(v15 - 1) != 1596014264 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64 *, __int64 (__fastcall *)()))v15)(
            a1,
            0,
            &v19,
            spectral_dbr_event_handler);
          v16 = a1;
        }
        v17 = (void (__fastcall *)(_QWORD))v11[83];
        if ( v17 )
        {
          if ( *((_DWORD *)v17 - 1) != -2099273483 )
            __break(0x8228u);
          v17(v16);
        }
      }
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: tx_ops is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_spectral_register_to_dbr",
      v19,
      v20);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
