__int64 __fastcall msm_vidc_enum_framesizes(_QWORD *a1, _DWORD *a2)
{
  int v5; // w0
  __int64 v6; // x1

  if ( *a2 )
    return 4294967274LL;
  v5 = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_vidc_enum_framesizes");
  v6 = (unsigned int)a2[1];
  if ( (_DWORD)v6 == v5
    || (unsigned int)v4l2_codec_to_driver(a1, v6, "msm_vidc_enum_framesizes")
    || (unsigned int)v4l2_colorformat_to_driver(a1, (unsigned int)a2[1], "msm_vidc_enum_framesizes") )
  {
    a2[2] = 3;
    a2[3] = a1[2137];
    a2[4] = a1[2138];
    a2[5] = a1[2139];
    a2[6] = a1[2200];
    a2[7] = a1[2201];
    a2[8] = a1[2202];
    return 0;
  }
  else
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_87351, "err ", (char *)a1 + 340, "msm_vidc_enum_framesizes", (unsigned int)a2[1]);
    }
    return 4294967274LL;
  }
}
