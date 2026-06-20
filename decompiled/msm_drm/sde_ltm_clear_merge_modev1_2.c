__int64 __fastcall sde_ltm_clear_merge_modev1_2(__int64 a1)
{
  if ( a1 )
    return sde_reg_write(
             a1,
             (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 24),
             0,
             "ctx->cap->sblk->ltm.base + 0x18");
  else
    return _drm_err("invalid parameters ctx %pK\n", nullptr);
}
