__int64 __fastcall hfi_crtc_atomic_begin(__int64 *a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 cmd_buf; // x0

  if ( a1 )
  {
    if ( *a1 )
    {
      v2 = *(_QWORD *)(*a1 + 56);
      if ( v2 )
      {
        v3 = *(_QWORD *)(v2 + 8);
        if ( v3 )
        {
          v4 = *(_QWORD *)(v3 + 6440);
          if ( v4 )
          {
            hfi_crtc_get_display_id(a1, a1[251]);
            cmd_buf = hfi_kms_get_cmd_buf(v4, 0, 1);
            if ( cmd_buf )
            {
              hfi_crtc_populate_props(cmd_buf, 0, a1, a2);
              return 0;
            }
            printk(&unk_211E26, "hfi_crtc_atomic_begin");
          }
        }
      }
    }
  }
  else
  {
    printk(&unk_211DA1, "hfi_crtc_atomic_begin");
  }
  return 4294967274LL;
}
