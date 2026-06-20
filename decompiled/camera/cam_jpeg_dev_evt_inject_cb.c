__int64 __fastcall cam_jpeg_dev_evt_inject_cb(__int64 a1)
{
  void *v1; // x8
  int v2; // w6

  v1 = &unk_3AB930;
  v2 = *(_DWORD *)(a1 + 48);
  if ( dword_3AB96C == v2 )
    goto LABEL_25;
  v1 = &unk_3ABB58;
  if ( dword_3ABB94 == v2 )
    goto LABEL_25;
  v1 = &unk_3ABD80;
  if ( dword_3ABDBC == v2 )
    goto LABEL_25;
  v1 = &unk_3ABFA8;
  if ( dword_3ABFE4 == v2 )
    goto LABEL_25;
  v1 = &unk_3AC1D0;
  if ( dword_3AC20C == v2 )
    goto LABEL_25;
  v1 = &unk_3AC3F8;
  if ( dword_3AC434 == v2 )
    goto LABEL_25;
  v1 = &unk_3AC620;
  if ( dword_3AC65C == v2 )
    goto LABEL_25;
  v1 = &unk_3AC848;
  if ( dword_3AC884 == v2 )
    goto LABEL_25;
  v1 = &unk_3ACA70;
  if ( dword_3ACAAC == v2 )
    goto LABEL_25;
  v1 = &unk_3ACC98;
  if ( dword_3ACCD4 == v2 )
    goto LABEL_25;
  v1 = &unk_3ACEC0;
  if ( dword_3ACEFC == v2 )
    goto LABEL_25;
  v1 = &unk_3AD0E8;
  if ( dword_3AD124 == v2 )
    goto LABEL_25;
  v1 = &unk_3AD310;
  if ( dword_3AD34C == v2 )
    goto LABEL_25;
  v1 = &unk_3AD538;
  if ( dword_3AD574 == v2 )
    goto LABEL_25;
  v1 = &unk_3AD760;
  if ( dword_3AD79C == v2 )
    goto LABEL_25;
  v1 = &unk_3AD988;
  if ( dword_3AD9C4 == v2 )
    goto LABEL_25;
  v1 = &unk_3ADBB0;
  if ( dword_3ADBEC == v2
    || (v1 = &unk_3ADDD8, dword_3ADE14 == v2)
    || (v1 = &unk_3AE000, dword_3AE03C == v2)
    || (v1 = &unk_3AE228, dword_3AE264 == v2)
    || (v1 = &unk_3AE450, dword_3AE48C == v2)
    || (v1 = &unk_3AE678, dword_3AE6B4 == v2)
    || (v1 = &unk_3AE8A0, dword_3AE8DC == v2)
    || (v1 = &unk_3AEAC8, dword_3AEB04 == v2) )
  {
LABEL_25:
    cam_context_add_evt_inject((__int64)v1, a1 + 16);
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_evt_inject_cb",
      42,
      "No dev hdl found %d",
      v2);
    return 4294967274LL;
  }
}
