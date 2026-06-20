__int64 __fastcall wmi_cmp_and_set_abi_version(int a1, __int64 a2, int *a3, int *a4, unsigned int *a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  int v19; // w25
  int v20; // w8
  unsigned int v21; // w22
  unsigned int v22; // w21
  unsigned int v23; // w26
  _DWORD *v24; // x8
  __int64 v25; // x9
  unsigned int v26; // w25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  __int64 v37; // [xsp+0h] [xbp-20h]
  __int64 v38; // [xsp+8h] [xbp-18h]
  __int64 v39; // [xsp+10h] [xbp-10h]
  unsigned int v40; // [xsp+18h] [xbp-8h]

  qdf_mem_copy(a5, a3, 0x18u);
  if ( a3[2] != a4[2] || a3[3] != a4[3] )
    goto LABEL_26;
  if ( a3[4] != a4[4] || a3[5] != a4[5] || *a3 != *a4 )
  {
    if ( a3[4] == a4[4] && a3[5] == a4[5] )
    {
      v19 = *a3;
      v20 = *a4;
      v21 = HIBYTE(*a3);
      if ( v21 == HIBYTE(*a4) )
      {
        v22 = v19 & 0xFFFFFF;
        v23 = v20 & 0xFFFFFF;
        if ( (v19 & 0xFFFFFFu) >= (v20 & 0xFFFFFFu) )
        {
          if ( v22 <= v23 )
          {
            qdf_mem_copy(a5, a3, 0x18u);
            v18 = 0;
            v36 = "%s: %s: Host downgraded WMI Versions to match fw. Ret version: Mj=%d, Mn=%d, bd=%d, ns0=0x%x ns1:0x%x "
                  "ns2:0x%x ns3:0x%x\n";
LABEL_28:
            v26 = *a5;
            goto LABEL_29;
          }
          if ( a1 >= 1 )
          {
            do
            {
              v24 = (_DWORD *)(a2 + 12);
              v25 = (unsigned int)a1;
              while ( *(v24 - 3) != v21
                   || *(v24 - 1) != a3[2]
                   || *v24 != a3[3]
                   || v24[1] != a3[4]
                   || v24[2] != a3[5]
                   || *(v24 - 2) != v22 )
              {
                --v25;
                v24 += 6;
                if ( !v25 )
                  goto LABEL_24;
              }
              LODWORD(v39) = v24[2];
              LODWORD(v38) = v24[1];
              LODWORD(v37) = *v24;
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: %s: Note: found a allowlist entry to downgrade. wh. list ver: %d,%d,0x%x 0x%x 0x%x 0x%x\n",
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                "wmi_versions_can_downgrade",
                "wmi_versions_can_downgrade",
                v21,
                v22--,
                v37,
                v38,
                v39);
            }
            while ( v22 > v23 );
            v22 = v23;
          }
LABEL_24:
          qdf_mem_copy(a5, a3, 0x18u);
          v26 = v19 & 0xFF000000 | v22 & 0xFFFFFF;
          *a5 = v26;
          if ( v22 == v23 )
          {
            v18 = 0;
            v36 = "%s: %s: Host downgraded WMI Versions to match fw. Ret version: Mj=%d, Mn=%d, bd=%d, ns0=0x%x ns1:0x%x "
                  "ns2:0x%x ns3:0x%x\n";
LABEL_29:
            v40 = a5[5];
            LODWORD(v39) = a5[4];
            LODWORD(v38) = a5[3];
            LODWORD(v37) = a5[2];
            qdf_trace_msg(
              0x38u,
              2u,
              v36,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "wmi_cmp_and_set_abi_version",
              "wmi_cmp_and_set_abi_version",
              HIBYTE(v26),
              v26 & 0xFFFFFF,
              a5[1],
              v37,
              v38,
              v39,
              v40);
            return v18;
          }
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: %s: Warning: incompatible WMI version and cannot downgrade.\n",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wmi_versions_can_downgrade",
            "wmi_versions_can_downgrade");
LABEL_27:
          v18 = 1;
          v36 = "%s: %s: WARN: Host WMI Versions mismatch with fw. Ret version: Mj=%d, Mn=%d, bd=%d, ns0=0x%x ns1:0x%x ns"
                "2:0x%x ns3:0x%x\n";
          goto LABEL_28;
        }
      }
    }
LABEL_26:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %s: Warning: incompatible WMI version.\n",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wmi_versions_can_downgrade",
      "wmi_versions_can_downgrade");
    qdf_mem_copy(a5, a3, 0x18u);
    goto LABEL_27;
  }
  return 0;
}
