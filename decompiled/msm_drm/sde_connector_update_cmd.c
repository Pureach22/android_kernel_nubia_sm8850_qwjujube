__int64 __fastcall sde_connector_update_cmd(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  unsigned int *v5; // x8
  char v7; // w21
  __int64 (__fastcall *v8)(__int64, __int64 *); // x8
  unsigned int v9; // w0
  int v10; // w6
  unsigned int v11; // w21
  int v12; // w0
  int v13; // w4
  int v14; // w7
  int v15; // w5
  void *v16; // x0
  __int64 v18; // [xsp+10h] [xbp-30h] BYREF
  int v19[2]; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v16 = &unk_215A31;
LABEL_12:
    printk(v16, "sde_connector_update_cmd");
    v11 = -22;
    goto LABEL_13;
  }
  v4 = *(_QWORD *)(a1 + 2760);
  if ( !v4 )
  {
    v16 = &unk_249B41;
    goto LABEL_12;
  }
  if ( *(_QWORD *)(a1 + 3152) )
  {
    v5 = *(unsigned int **)(a1 + 2744);
    v7 = a3 & 1;
    v21 = 0;
    v22 = 0;
    *(_QWORD *)v19 = 0;
    v20 = 0;
    v18 = 0;
    if ( (a3 & 1) != 0 )
    {
      sde_encoder_update_periph_flush(v5, a2);
      v4 = *(_QWORD *)(a1 + 2760);
    }
    v8 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 3280);
    *(_QWORD *)v19 = a2;
    LOBYTE(v20) = v7;
    if ( *((_DWORD *)v8 - 1) != -987377525 )
      __break(0x8228u);
    v9 = v8(v4, &v18);
    v10 = v19[0];
    v11 = v9;
    v12 = sde_dbg_base_evtlog;
    v13 = *(_DWORD *)(a1 + 64);
    v14 = (unsigned __int8)v20;
    v15 = v19[1];
    *(_QWORD *)(a1 + 4736) = a2;
    sde_evtlog_log(v12, "sde_connector_update_cmd", 1814, -1, v13, v15, v10, v14, v11);
  }
  else
  {
    v11 = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v11;
}
