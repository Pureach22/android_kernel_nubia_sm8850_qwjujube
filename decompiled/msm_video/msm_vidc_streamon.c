__int64 __fastcall msm_vidc_streamon(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  unsigned int v4; // w0
  __int64 result; // x0
  __int64 v6; // x2
  unsigned int v7; // w20

  v2 = a2;
  v4 = v4l2_type_to_driver_port(a1, a2, "msm_vidc_streamon");
  if ( (v4 & 0x80000000) != 0 )
    return 4294967274LL;
  if ( v4 >= 5 )
  {
    __break(0x5512u);
    return msm_vidc_streamoff();
  }
  else
  {
    result = vb2_streamon(*(_QWORD *)(a1 + 8LL * v4 + 1840), v2);
    if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    {
      v6 = a1 + 340;
      v7 = result;
      printk(&unk_8D6AE, "err ", v6, "msm_vidc_streamon", v2);
      return v7;
    }
  }
  return result;
}
