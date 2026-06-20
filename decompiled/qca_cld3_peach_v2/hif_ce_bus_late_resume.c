__int64 __fastcall hif_ce_bus_late_resume(__int64 a1)
{
  unsigned __int64 v2; // x20
  unsigned int v3; // w23
  __int64 v4; // x25
  unsigned __int64 StatusReg; // x26
  __int64 v6; // x21
  int v7; // w8
  int v8; // w22
  __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w10
  int v12; // w11
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x1
  unsigned int v16; // w22
  unsigned int v17; // w24
  __int64 v18; // x8
  int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x7
  __int64 v23; // [xsp+0h] [xbp-10h] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 656) )
  {
    v2 = 0;
    v3 = 0;
    v4 = a1 + 28672;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      if ( v2 == 12 )
        __break(0x5512u);
      v6 = *(_QWORD *)(a1 + 8 * v2 + 480);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v6 + 168);
      }
      else
      {
        raw_spin_lock_bh(v6 + 168);
        *(_QWORD *)(v6 + 176) |= 1uLL;
      }
      v7 = *(_DWORD *)(v6 + 20);
      v8 = 0;
      if ( v7 != 1 )
      {
        if ( v7 != 3 )
          goto LABEL_19;
        v9 = *(_QWORD *)(a1 + 616);
        v10 = *(_QWORD *)(v6 + 136);
        v11 = *(_DWORD *)(v6 + 16);
        v12 = *(unsigned __int8 *)(v4 + 2417);
        v23 = 0;
        v3 = *(_DWORD *)(v10 + 12);
        v13 = (unsigned int)(*(_DWORD *)(v9 + 352) + v11);
        v14 = *(_QWORD *)(a1 + 30720);
        v15 = *(_QWORD *)(a1 + 40) + v13;
        if ( v12 == 1 && (v16 = v15 - v14, (unsigned int)(v15 - v14) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), &v23);
          v17 = (v16 >> 19) & 0x3F | 0x40000000;
          writel_0(v17, *(_QWORD *)(a1 + 30720) + 12920LL);
          v18 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(v4 + 2420) = (v16 >> 19) & 0x3F;
          v19 = readl_0(v18 + 12920);
          if ( v19 != v17 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v17,
              v19,
              12920);
          writel_0(v3, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v16 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), &v23);
        }
        else
        {
          writel_0(v3, v15);
        }
        v8 = 1;
      }
      *(_DWORD *)(v6 + 20) = 2;
LABEL_19:
      v20 = *(_QWORD *)(v6 + 176);
      if ( (v20 & 1) != 0 )
      {
        *(_QWORD *)(v6 + 176) = v20 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v6 + 168);
        if ( !v8 )
          goto LABEL_3;
LABEL_21:
        hif_record_ce_desc_event(a1, (unsigned int)v2, 11, 0, 0, v3, 0, v21, v23, v24);
        goto LABEL_3;
      }
      raw_spin_unlock(v6 + 168);
      if ( v8 )
        goto LABEL_21;
LABEL_3:
      ++v2;
    }
    while ( v2 < *(unsigned int *)(a1 + 656) );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
