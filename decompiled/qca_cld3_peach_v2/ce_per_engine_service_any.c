__int64 __fastcall ce_per_engine_service_any(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x11
  int v6; // w10
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  unsigned int v10; // w21
  unsigned int v11; // w20
  __int64 v12; // x8
  int v13; // w0
  unsigned int v14; // w20
  unsigned __int64 v15; // x8
  unsigned __int64 i; // x20
  __int64 v17; // x9
  unsigned int v18; // w21
  unsigned int v19; // w20
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = hif_target_sleep_state_adjust(a2, 0, 1);
  if ( (result & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(a2 + 720) )
    {
      v4 = *(_QWORD *)(a2 + 624);
      v5 = *(_QWORD *)(a2 + 40);
      v6 = *(unsigned __int8 *)(a2 + 31089);
      v20[0] = 0;
      v7 = (unsigned int)(*(_DWORD *)(v4 + 64) + *(_DWORD *)(v4 + 60));
      v8 = *(_QWORD *)(a2 + 30720);
      v9 = v5 + v7;
      if ( v6 == 1 && (v10 = v9 - v8, (unsigned int)(v9 - v8) >> 19) )
      {
        pld_lock_reg_window(*(_QWORD *)(a2 + 30760), v20);
        v11 = (v10 >> 19) & 0x3F | 0x40000000;
        writel_1(v11, *(_QWORD *)(a2 + 30720) + 12920LL);
        v12 = *(_QWORD *)(a2 + 30720);
        *(_DWORD *)(a2 + 31092) = (v10 >> 19) & 0x3F;
        v13 = readl_1(v12 + 12920);
        if ( v13 != v11 )
          qdf_trace_msg(
            61,
            2,
            "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
            "hif_reg_write_result_check",
            v11,
            v13,
            12920);
        v14 = readl_1(*(_QWORD *)(a2 + 30720) + (*(_QWORD *)&v10 & 0x7FFFFLL) + 0x80000);
        pld_unlock_reg_window(*(_QWORD *)(a2 + 30760), v20);
      }
      else
      {
        v14 = readl_1(v9);
      }
      v18 = (*(_DWORD *)(*(_QWORD *)(a2 + 624) + 192LL) & v14) >> *(_DWORD *)(*(_QWORD *)(a2 + 624) + 196LL);
      if ( v18 )
      {
        v19 = 0;
        do
        {
          if ( v19 >= *(_DWORD *)(a2 + 656) )
            break;
          if ( (v18 & (1 << v19)) != 0 )
          {
            v18 &= ~(1 << v19);
            ce_per_engine_service(a2, v19);
          }
          ++v19;
        }
        while ( v18 );
      }
    }
    else
    {
      v15 = *(unsigned int *)(a2 + 656);
      if ( (_DWORD)v15 )
      {
        for ( i = 0; i < v15; ++i )
        {
          if ( i == 12 )
            __break(0x5512u);
          v17 = *(_QWORD *)(a2 + 8 * i + 480);
          if ( *(_DWORD *)(v17 + 160) )
          {
            *(_DWORD *)(v17 + 160) = 0;
            ce_per_engine_service(a2, i);
            v15 = *(unsigned int *)(a2 + 656);
          }
        }
      }
    }
    result = hif_target_sleep_state_adjust(a2, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
