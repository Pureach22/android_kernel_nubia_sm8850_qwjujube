__int64 __fastcall ufs_qcom_mcq_esi_handler(unsigned int a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x19
  __int64 v5; // x3
  unsigned int v6; // w20
  __int64 v7; // x21
  __int64 v8; // x0
  unsigned int v16; // w9
  unsigned int v19; // w10

  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 152LL);
  if ( v4 )
  {
    v3 = *(_QWORD *)(v4 + 184);
    v5 = a1;
    v6 = *(unsigned __int16 *)(a2 + 72);
    v7 = *(_QWORD *)(v4 + 5072);
    v8 = *(_QWORD *)(v3 + 656);
    if ( v8 && *(_BYTE *)(v3 + 664) == 1 )
      ipc_log_string(v8, ",%d,!,%d,%u\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40), v5, v6);
    v2 = v7 + 144LL * v6;
    ufshcd_mcq_write_cqis(v4, 1, v6, v5);
  }
  else
  {
    __break(0x800u);
  }
  _X8 = (unsigned int *)(v3 + 3144);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 + 1, _X8) );
  ufshcd_mcq_poll_cqe_lock(v4, v2);
  _X8 = (unsigned int *)(v3 + 3144);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 - 1, _X8) );
  return 1;
}
