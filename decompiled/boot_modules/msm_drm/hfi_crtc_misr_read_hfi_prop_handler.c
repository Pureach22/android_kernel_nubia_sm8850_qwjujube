__int64 __fastcall hfi_crtc_misr_read_hfi_prop_handler(__int64 a1, __int64 a2, _DWORD *a3, int a4, __int64 a5)
{
  __int64 v6; // x21
  int v7; // w20
  int *v8; // x22
  __int64 result; // x0

  if ( a5 )
  {
    if ( a3 && a4 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        result = _drm_dev_dbg(0, 0, 0, "About to read MISR values from %s\n", "hfi_crtc_misr_read_hfi_prop_handler");
        v6 = *(_QWORD *)(a5 - 80);
        v7 = a3[1];
        v8 = (int *)(v6 + 7364);
        if ( (_drm_debug & 4) != 0 )
          result = _drm_dev_dbg(0, 0, 0, "crtc_id:%d, Module_type:%d, Max_count:%d\n", *(_DWORD *)(v6 + 112), *a3, v7);
      }
      else
      {
        v6 = *(_QWORD *)(a5 - 80);
        v7 = a3[1];
        v8 = (int *)(v6 + 7364);
      }
      *(_QWORD *)(v6 + 7376) = 0;
      *(_QWORD *)(v6 + 7368) = 0;
      if ( !v7
        || (*(_DWORD *)(v6 + 7368) = a3[2], v7 == 1)
        || (*(_DWORD *)(v6 + 7372) = a3[3], v7 == 2)
        || (*(_DWORD *)(v6 + 7376) = a3[4], v7 == 3)
        || (*(_DWORD *)(v6 + 7380) = a3[5], v7 == 4) )
      {
        *v8 = v7;
      }
      else
      {
        __break(0x5512u);
        return hfi_crtc_debugfs_misr_read();
      }
    }
    else
    {
      return printk(&unk_24F8BD, "hfi_crtc_misr_read_hfi_prop_handler");
    }
  }
  return result;
}
