__int64 __fastcall sde_plane_is_cache_required(__int64 a1, int a2)
{
  __int64 v2; // x21
  int v5; // w7
  __int64 result; // x0
  int v7; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v8[2]; // [xsp+30h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v7 = 0;
  if ( !a1 || (v2 = *(_QWORD *)(a1 + 1768)) == 0 )
  {
    printk(&unk_226FC0, "sde_plane_is_cache_required");
    goto LABEL_11;
  }
  msm_framebuffer_get_cache_hint(*(_QWORD *)(v2 + 16), (char *)v8 + 4, v8, &v7);
  if ( *(_BYTE *)(v2 + 2716) != 1 )
  {
LABEL_11:
    result = 0;
    goto LABEL_12;
  }
  v5 = *(_DWORD *)(v2 + 2736);
  if ( v5 == a2 || HIDWORD(v8[0]) && LODWORD(v8[0]) == a2 || (result = 0, HIDWORD(v8[0])) && v7 == a2 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_plane_is_cache_required",
      4314,
      4,
      *(_DWORD *)(a1 + 104),
      a2,
      1,
      v5,
      SBYTE4(v8[0]));
    result = 1;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
