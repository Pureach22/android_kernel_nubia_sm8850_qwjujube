__int64 __fastcall msm_vidc_v4l2_menu_to_hfi(__int64 result, unsigned int a2, _DWORD *a3)
{
  unsigned __int64 v3; // x8

  if ( a2 == 41 )
  {
    v3 = *(_QWORD *)(result + 11240);
    if ( v3 > 1 )
    {
      *a3 = 1;
      if ( result )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_8A39B, "err ", result + 340, "msm_vidc_v4l2_menu_to_hfi", *(_QWORD *)(result + 11240));
        return 0;
      }
    }
    else
    {
      *a3 = v3;
      return 0;
    }
  }
  else
  {
    if ( result && (msm_vidc_debug & 1) != 0 )
    {
      if ( a2 > 0xC5 )
      {
        __break(0x5512u);
        JUMPOUT(0x28B34);
      }
      printk(
        &unk_8C607,
        "err ",
        result + 340,
        "msm_vidc_v4l2_menu_to_hfi",
        *(unsigned int *)(result + 168LL * a2 + 4360));
    }
    return 4294967274LL;
  }
  return result;
}
