__int64 __fastcall wlan_dp_svc_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  _QWORD *v11; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x118u, "wlan_dp_svc_init", 342);
    if ( v10 )
    {
      v11 = (_QWORD *)v10;
      *(_DWORD *)(v10 + 264) = 0;
      *(_QWORD *)(v10 + 272) = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v10 + 264);
      }
      else
      {
        raw_spin_lock_bh(v10 + 264);
        v11[34] |= 1uLL;
      }
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
      v11[3] = 0;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      v11[7] = 0;
      v11[8] = 0;
      v11[9] = 0;
      v11[10] = 0;
      v11[11] = 0;
      v11[12] = 0;
      v11[13] = 0;
      v11[14] = 0;
      v11[15] = 0;
      v11[16] = 0;
      v11[17] = 0;
      v11[18] = 0;
      v11[19] = 0;
      v11[20] = 0;
      v11[21] = 0;
      v11[22] = 0;
      v11[23] = 0;
      v11[24] = 0;
      v11[25] = 0;
      v11[26] = 0;
      v11[27] = 0;
      v11[28] = 0;
      v11[29] = 0;
      v11[30] = 0;
      v11[31] = 0;
      v13 = v11[34];
      if ( (v13 & 1) != 0 )
      {
        v11[34] = v13 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v11 + 33);
      }
      else
      {
        raw_spin_unlock(v11 + 33);
      }
      *(_QWORD *)(a1 + 1552) = v11;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: service_class init successful",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_dp_svc_init");
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP context not found", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_svc_init");
    return 16;
  }
}
