__int64 __fastcall ipa_nat_ipv6ct_stringify_entry_v_4_0(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w9
  unsigned int v7; // w10
  unsigned int v8; // w11
  int v9; // w23
  unsigned int v10; // w10
  unsigned int v11; // w11
  unsigned int v12; // w9
  int v13; // w0
  unsigned __int64 v14; // x9
  __int64 v15; // x11
  int v16; // w22
  const char *v17; // x3
  const char *v18; // x4
  const char *v19; // x10
  const char *v20; // x14
  int v21; // w0
  unsigned int v23; // [xsp+28h] [xbp-18h] BYREF
  unsigned int v24; // [xsp+2Ch] [xbp-14h]
  unsigned int v25; // [xsp+30h] [xbp-10h]
  unsigned int v26; // [xsp+34h] [xbp-Ch]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 8);
  v8 = *(_DWORD *)a1;
  v7 = *(_DWORD *)(a1 + 4);
  v23 = bswap32(*(_DWORD *)(a1 + 12));
  v24 = bswap32(v6);
  v25 = bswap32(v7);
  v26 = bswap32(v8);
  v9 = scnprintf(a2, a3, "\t\t%s_IPv6_Addr=%pI6c\n", "Src", &v23);
  v11 = *(_DWORD *)(a1 + 16);
  v10 = *(_DWORD *)(a1 + 20);
  v12 = bswap32(*(_DWORD *)(a1 + 24));
  v23 = bswap32(*(_DWORD *)(a1 + 28));
  v24 = v12;
  v25 = bswap32(v10);
  v26 = bswap32(v11);
  v13 = scnprintf(a2 + v9, a3 - v9, "\t\t%s_IPv6_Addr=%pI6c\n", "Dest", &v23);
  v14 = *(_QWORD *)(a1 + 32);
  v15 = *(_QWORD *)(a1 + 40);
  v16 = v13 + v9;
  if ( (v14 & 0x80000000) != 0LL )
    v17 = "true";
  else
    v17 = "false";
  if ( (v14 & 0x40000000) != 0 )
    v18 = "Direct_To_APPS";
  else
    v18 = "Fwd_to_route";
  v19 = "Allow";
  if ( (v15 & 0x40000000000000LL) != 0 )
    v20 = "Allow";
  else
    v20 = "Deny";
  if ( (v15 & 0x80000000000000LL) == 0 )
    v19 = "Deny";
  v21 = scnprintf(
          a2 + v16,
          a3 - v16,
          "\t\tEnable=%s Redirect=%s Time_Stamp=0x%x Proto=%d\n"
          "\t\tNext_Index=%d Dest_Port=%d Src_Port=%d\n"
          "\t\tDirection Settings: Out=%s In=%s\n"
          "\t\tPrev_Index=%d\n",
          v17,
          v18,
          HIDWORD(v14) & 0xFFFFFF,
          HIBYTE(v14),
          (unsigned __int16)*(_QWORD *)(a1 + 40),
          WORD1(*(_QWORD *)(a1 + 40)),
          (unsigned __int16)WORD2(*(_QWORD *)(a1 + 40)),
          v20,
          v19,
          *(unsigned __int16 *)(a1 + 54));
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v21 + v16);
}
