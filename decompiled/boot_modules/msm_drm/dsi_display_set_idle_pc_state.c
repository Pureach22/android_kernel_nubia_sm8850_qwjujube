__int64 __fastcall dsi_display_set_idle_pc_state(__int64 result, char a2)
{
  unsigned int v2; // w9
  __int64 v3; // x10
  char v4; // w8
  __int64 v5; // x9

  if ( !result )
    return drm_dev_printk((unsigned __int8)result, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid arg\n");
  v2 = *(_DWORD *)(result + 160);
  if ( v2 )
  {
    v3 = *(_QWORD *)(result + 168);
    v4 = a2 & 1;
    if ( v3 )
    {
      *(_BYTE *)(v3 + 1648) = v4;
      v2 = *(_DWORD *)(result + 160);
    }
    if ( v2 >= 2 )
    {
      v5 = *(_QWORD *)(result + 216);
      if ( v5 )
        *(_BYTE *)(v5 + 1648) = v4;
    }
  }
  return result;
}
