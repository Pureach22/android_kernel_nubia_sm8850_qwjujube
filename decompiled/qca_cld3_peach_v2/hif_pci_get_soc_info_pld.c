__int64 __fastcall hif_pci_get_soc_info_pld(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x21
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w5
  int v8; // w6
  int v9; // w7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x9
  int v21; // [xsp+0h] [xbp-140h]
  _QWORD s[38]; // [xsp+10h] [xbp-130h] BYREF

  v4 = (_DWORD *)(a1 + 28672);
  s[37] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x128u);
  pld_get_soc_info(a2, s);
  v5 = s[0];
  v6 = s[1];
  v7 = s[9];
  v8 = HIDWORD(s[9]);
  *(_QWORD *)(a1 + 30720) = s[0];
  *(_QWORD *)(a1 + 40) = v5;
  v9 = s[10];
  LODWORD(v5) = HIDWORD(s[10]);
  *(_QWORD *)(a1 + 728) = v6;
  v4[643] = v7;
  v4[644] = v8;
  v4[645] = v9;
  v4[646] = v5;
  v21 = v5;
  result = qdf_trace_msg(
             0x3Du,
             5u,
             "%s: %s: fam num %u dev ver %u maj ver %u min ver %u",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "hif_pci_get_soc_info_pld",
             "hif_pci_get_soc_info_pld",
             v21);
  v19 = s[11];
  v20 = s[12];
  *(_DWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 4016) = v19;
  LODWORD(v19) = HIDWORD(s[3]);
  *(_QWORD *)(a1 + 4024) = v20;
  LODWORD(v20) = s[10];
  *(_DWORD *)(a1 + 16) = v19;
  _ReadStatusReg(SP_EL0);
  *(_DWORD *)(a1 + 28) = v20;
  return result;
}
