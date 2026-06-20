__int64 __fastcall drv_cmd_get_sap_go_linkspeed(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  unsigned int v6; // w8
  __int64 result; // x0
  unsigned __int8 v9; // w0
  int v10; // w8
  __int64 v11; // x19
  unsigned __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x9
  const char *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD v42[9]; // [xsp+8h] [xbp-48h] BYREF

  v42[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v6 = *(_DWORD *)(*a1 + 40);
  memset(v42, 0, 64);
  if ( (v6 | 2) == 3 )
  {
    result = wlan_hdd_get_sap_go_peer_linkspeed();
    if ( !(_DWORD)result )
    {
      scnprintf(v42, 64, "%s %d\n", "SOFT-AP LINKSPEED", 0);
      v10 = *(_DWORD *)(a5 + 12);
      if ( v10 > v9 )
        LOBYTE(v10) = v9 + 1;
      v11 = (unsigned __int8)v10;
      if ( (unsigned __int8)v10 >= 0x41u )
      {
        _copy_overflow(64, (unsigned __int8)v10);
      }
      else
      {
        v12 = *(_QWORD *)a5;
        _check_object_size(v42, (unsigned __int8)v10, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v22 = v12, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v22 = v12 & ((__int64)(v12 << 8) >> 8);
        if ( 0x8000000000LL - v11 >= v22 )
        {
          v23 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v29 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v29);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v23);
          v11 = _arch_copy_to_user(v12 & 0xFF7FFFFFFFFFFFFFLL, v42, v11);
          v30 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v32 - 4096);
          _WriteStatusReg(TTBR1_EL1, v32);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v30);
        }
        if ( !v11 )
        {
          result = 0;
          goto LABEL_15;
        }
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to copy data to user buffer",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "drv_cmd_get_sap_go_linkspeed");
      result = 4294967282LL;
    }
  }
  else
  {
    v33 = qdf_opmode_str(v6);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Link Speed is not allowed in Device mode %s(%d)",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "drv_cmd_get_sap_go_linkspeed",
      v33,
      *(unsigned int *)(v5 + 40));
    result = 4294966772LL;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
