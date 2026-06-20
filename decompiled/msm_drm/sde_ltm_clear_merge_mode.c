__int64 __fastcall sde_ltm_clear_merge_mode(__int64 a1)
{
  int v2; // w0

  if ( !a1 )
    return _drm_err("invalid parameters ctx %pK\n", nullptr);
  v2 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 4));
  return sde_reg_write(
           a1,
           (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 4),
           v2 & 0xFFFCFFFF,
           "ctx->cap->sblk->ltm.base + 0x04");
}
