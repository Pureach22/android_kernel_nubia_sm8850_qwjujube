__int64 __fastcall msm_vidc_querybuf(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  __int64 result; // x0
  __int64 v6; // x2
  unsigned int v7; // w19

  v4 = v4l2_type_to_driver_port(a1, *(unsigned int *)(a2 + 4), "msm_vidc_querybuf");
  if ( (v4 & 0x80000000) != 0 )
    return 4294967274LL;
  if ( v4 >= 5 )
  {
    __break(0x5512u);
    JUMPOUT(0x47BC4);
  }
  result = vb2_querybuf(*(_QWORD *)(a1 + 8LL * v4 + 1840), a2);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v6 = a1 + 340;
    v7 = result;
    printk(&unk_80F73, "err ", v6, "msm_vidc_querybuf", *(unsigned int *)(a2 + 4));
    return v7;
  }
  return result;
}
