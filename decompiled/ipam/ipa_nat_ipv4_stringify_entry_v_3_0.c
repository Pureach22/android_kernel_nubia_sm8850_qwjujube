__int64 __fastcall ipa_nat_ipv4_stringify_entry_v_3_0(_QWORD *a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x12
  const char *v4; // x9
  const char *v5; // x14

  v3 = a1[2];
  v4 = "true";
  v5 = "Direct_To_APPS";
  if ( (v3 & 0x80000000) == 0LL )
    v4 = "false";
  if ( (v3 & 0x40000000) == 0 )
    v5 = "Fwd_to_route";
  return scnprintf(
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
           (unsigned __int16)a1[1],
           WORD1(a1[1]),
           (unsigned __int16)WORD2(a1[1]),
           HIWORD(a1[1]),
           (unsigned __int16)a1[2],
           v4,
           v5,
           HIDWORD(v3) & 0xFFFFFF,
           HIBYTE(v3),
           (unsigned __int16)a1[3],
           WORD1(a1[3]),
           HIWORD(a1[3]));
}
