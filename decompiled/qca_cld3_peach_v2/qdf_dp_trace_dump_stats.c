__int64 __fastcall qdf_dp_trace_dump_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  int v9; // [xsp+0h] [xbp-90h]
  int v10; // [xsp+8h] [xbp-88h]
  int v11; // [xsp+10h] [xbp-80h]
  int v12; // [xsp+18h] [xbp-78h]
  int v13; // [xsp+20h] [xbp-70h]
  int v14; // [xsp+28h] [xbp-68h]
  int v15; // [xsp+30h] [xbp-60h]
  int v16; // [xsp+38h] [xbp-58h]
  int v17; // [xsp+40h] [xbp-50h]
  int v18; // [xsp+48h] [xbp-48h]
  int v19; // [xsp+50h] [xbp-40h]
  int v20; // [xsp+58h] [xbp-38h]
  int v21; // [xsp+60h] [xbp-30h]
  int v22; // [xsp+68h] [xbp-28h]
  int v23; // [xsp+70h] [xbp-20h]
  int v24; // [xsp+78h] [xbp-18h]
  int v25; // [xsp+80h] [xbp-10h]
  int v26; // [xsp+88h] [xbp-8h]

  v20 = (unsigned __int16)word_7F7680;
  v19 = (unsigned __int16)word_7F767E;
  v18 = (unsigned __int16)word_7F767A;
  v26 = (unsigned __int16)word_7F768C;
  v25 = (unsigned __int16)word_7F768A;
  v24 = (unsigned __int16)word_7F7688;
  v23 = (unsigned __int16)word_7F7686;
  v22 = (unsigned __int16)word_7F7684;
  v21 = (unsigned __int16)word_7F7682;
  v17 = (unsigned __int16)word_7F767C;
  v16 = (unsigned __int16)word_7F7678;
  v15 = (unsigned __int16)word_7F769E;
  v14 = (unsigned __int16)word_7F769C;
  v13 = (unsigned __int16)word_7F7698;
  v12 = (unsigned __int16)word_7F7696;
  v11 = (unsigned __int16)word_7F7694;
  v10 = (unsigned __int16)word_7F7692;
  v9 = (unsigned __int16)word_7F7676;
  return qdf_trace_msg(
           0x38u,
           8u,
           "STATS |DPT: tx %u rx %u icmp(%u %u) arp(%u %u) icmpv6(%u %u %u %u %u %u) dhcp(%u %u %u %u %u %u) eapol(%u %u %u %u %u)",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           (unsigned int)dword_7F766C,
           (unsigned int)dword_7F7670,
           (unsigned __int16)word_7F768E,
           (unsigned __int16)word_7F7690,
           (unsigned __int16)word_7F7674,
           v9,
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           v26);
}
