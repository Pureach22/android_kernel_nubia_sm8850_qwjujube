__int64 __fastcall sde_encoder_get_intf_mode(__int64 a1)
{
  __int64 v1; // x8
  int v3; // w8
  __int64 v4; // x9

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 328);
    if ( v1 )
      return *(unsigned int *)(v1 + 668);
    v3 = *(_DWORD *)(a1 + 196);
    if ( !v3 )
      return 0;
    v4 = *(_QWORD *)(a1 + 200);
    if ( v4 )
      return *(unsigned int *)(v4 + 668);
    if ( v3 == 1 )
      return 0;
    v4 = *(_QWORD *)(a1 + 208);
    if ( v4 )
      return *(unsigned int *)(v4 + 668);
    if ( v3 == 2 )
      return 0;
    v4 = *(_QWORD *)(a1 + 216);
    if ( v4 )
      return *(unsigned int *)(v4 + 668);
    if ( v3 == 3 )
      return 0;
    v4 = *(_QWORD *)(a1 + 224);
    if ( v4 )
      return *(unsigned int *)(v4 + 668);
    if ( v3 == 4 )
    {
      return 0;
    }
    else
    {
      __break(0x5512u);
      return sde_encoder_get_frame_count(a1 + 172);
    }
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_get_intf_mode");
    return 0;
  }
}
