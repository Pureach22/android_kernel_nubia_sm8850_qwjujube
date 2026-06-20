void __fastcall target_process_bang_radar_cmd(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int128 a11,
        int a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49,
        __int64 a50,
        __int64 a51,
        __int64 a52,
        __int64 a53,
        __int64 a54,
        __int64 a55,
        __int64 a56,
        __int64 a57,
        __int64 a58,
        __int64 a59,
        __int64 a60,
        __int64 a61)
{
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 *v71; // x8
  __int64 v72; // x20
  unsigned int v73; // w8
  const char *v74; // x2

  a61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset((char *)&a11 + 4, 0, 0x194u);
  HIDWORD(a9) = 0;
  if ( a1 )
  {
    v71 = *(__int64 **)(a1 + 1240);
    if ( v71 && (v72 = *v71) != 0 )
    {
      v73 = a2[1];
      LODWORD(a10) = *a2;
      HIDWORD(a10) = 43;
      LODWORD(a11) = v73;
      if ( v73 )
      {
        DWORD2(a11) = a2[2];
        if ( v73 >= 3 )
        {
          a12 = a2[4];
          if ( v73 != 3 )
            JUMPOUT(0x6ED554);
        }
      }
      if ( !(unsigned int)wmi_convert_pdev_id_host_to_target(v72, *(unsigned __int8 *)(a1 + 40), (_DWORD *)&a9 + 1) )
        JUMPOUT(0x6ED50C);
      v74 = "%s: failed to convert host pdev id to target";
    }
    else
    {
      v74 = "%s: null wmi_handle";
    }
  }
  else
  {
    v74 = "%s: null pdev";
  }
  qdf_trace_msg(0x49u, 2u, v74, v63, v64, v65, v66, v67, v68, v69, v70, "target_process_bang_radar_cmd");
  if ( *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808) == a61 )
    JUMPOUT(0x6ED508);
  JUMPOUT(0x6ED550);
}
