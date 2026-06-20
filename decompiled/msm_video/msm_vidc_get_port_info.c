__int64 __fastcall msm_vidc_get_port_info(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  _BOOL8 v3; // x1

  if ( a2 >= 0xC6 )
  {
    __break(0x5512u);
    return msm_vidc_v4l2_menu_to_hfi();
  }
  else
  {
    v2 = *(_DWORD *)(a1 + 168LL * a2 + 4368);
    if ( (~v2 & 0xC) == 0 )
    {
      v3 = (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) == 0;
      return get_hfi_port(a1, v3);
    }
    if ( (v2 & 0xC) != 0 )
    {
      v3 = ((v2 >> 2) & 1) == 0;
      return get_hfi_port(a1, v3);
    }
    return 0;
  }
}
