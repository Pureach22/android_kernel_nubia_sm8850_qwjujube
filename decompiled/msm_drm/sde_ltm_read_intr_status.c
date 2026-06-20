__int64 __fastcall sde_ltm_read_intr_status(_QWORD *a1, _DWORD *a2)
{
  int v3; // w0

  if ( !a1 || !a2 )
    return _drm_err("invalid parameters ctx %pK status %pK\n", a1, a2);
  *a2 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 84));
  v3 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 88));
  return sde_reg_write(
           a1,
           (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 88),
           v3 | 6u,
           "ctx->cap->sblk->ltm.base + 0x58");
}
