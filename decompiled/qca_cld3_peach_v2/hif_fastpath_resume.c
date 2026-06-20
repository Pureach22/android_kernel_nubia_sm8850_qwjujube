__int64 __fastcall hif_fastpath_resume(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x10
  int v7; // w11
  __int64 v8; // x12
  unsigned int v9; // w20
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w24
  unsigned int v14; // w21
  __int64 v15; // x8
  int v16; // w0
  __int64 v17; // x8
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = result;
    if ( *(_BYTE *)(result + 716) == 1 )
    {
      result = hif_target_sleep_state_adjust(result);
      if ( (result & 0x80000000) == 0 )
      {
        v2 = *(_QWORD *)(v1 + 512);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v2 + 168);
        }
        else
        {
          raw_spin_lock_bh(v2 + 168);
          *(_QWORD *)(v2 + 176) |= 1uLL;
        }
        v4 = *(_QWORD *)(v1 + 616);
        v5 = *(_DWORD *)(v2 + 16);
        v6 = *(_QWORD *)(v2 + 136);
        v7 = *(unsigned __int8 *)(v1 + 31089);
        v8 = *(_QWORD *)(v1 + 40);
        v18[0] = 0;
        v9 = *(_DWORD *)(v6 + 12);
        v10 = (unsigned int)(*(_DWORD *)(v4 + 352) + v5);
        v11 = *(_QWORD *)(v1 + 30720);
        v12 = v8 + v10;
        if ( v7 == 1 && (v13 = v12 - v11, (unsigned int)(v12 - v11) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(v1 + 30760), v18);
          v14 = (v13 >> 19) & 0x3F | 0x40000000;
          writel_3(v14, *(_QWORD *)(v1 + 30720) + 12920LL);
          v15 = *(_QWORD *)(v1 + 30720);
          *(_DWORD *)(v1 + 31092) = (v13 >> 19) & 0x3F;
          v16 = readl_3(v15 + 12920);
          if ( v16 != v14 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v14,
              v16,
              12920);
          writel_3(v9, *(_QWORD *)(v1 + 30720) + (*(_QWORD *)&v13 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(v1 + 30760), v18);
        }
        else
        {
          writel_3(v9, v12);
        }
        v17 = *(_QWORD *)(v2 + 176);
        if ( (v17 & 1) != 0 )
        {
          *(_QWORD *)(v2 + 176) = v17 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v2 + 168);
        }
        else
        {
          raw_spin_unlock(v2 + 168);
        }
        result = hif_target_sleep_state_adjust(v1);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
