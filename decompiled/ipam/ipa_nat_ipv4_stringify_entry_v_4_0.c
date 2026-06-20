__int64 __fastcall ipa_nat_ipv4_stringify_entry_v_4_0(_QWORD *a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x9
  __int64 v4; // x11
  const char *v6; // x8
  const char *v8; // x13
  int v10; // w22

  v4 = a1[2];
  v6 = "true";
  v8 = "Direct_To_APPS";
  if ( (int)v4 >= 0 )
    v6 = "false";
  if ( (v4 & 0x40000000) == 0 )
    v8 = "Fwd_to_route";
  v3 = a1[1];
  v10 = scnprintf(
          a2,
          a3,
          "\t\tPrivate_IP=%pI4h  Target_IP=%pI4h\n"
          "\t\tNext_Index=%d  Public_Port=%d\n"
          "\t\tPrivate_Port=%d  Target_Port=%d\n"
          "\t\tIP_CKSM_delta=0x%x  Enable=%s  Redirect=%s\n"
          "\t\tTime_stamp=0x%x Proto=%d\n"
          "\t\tPrev_Index=%d  Indx_tbl_entry=%d\n"
          "\t\tTCP_UDP_cksum_delta=0x%x\n",
          a1,
          (char *)a1 + 4,
          (unsigned __int16)v3,
          WORD1(v3),
          WORD2(v3),
          HIWORD(v3),
          (unsigned __int16)a1[2],
          v6,
          v8,
          HIDWORD(a1[2]) & 0xFFFFFF,
          HIBYTE(a1[2]),
          (unsigned __int16)a1[3],
          WORD1(a1[3]),
          HIWORD(a1[3]));
  return (unsigned int)scnprintf(a2 + v10, a3 - v10, "\t\tPDN_Index=%d\n", (a1[3] >> 44) & 0xF) + v10;
}
