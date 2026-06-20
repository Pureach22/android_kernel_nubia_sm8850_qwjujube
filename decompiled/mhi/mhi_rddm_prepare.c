__int64 __fastcall mhi_rddm_prepare(__int64 a1, __int64 *a2)
{
  __int64 v2; // x22
  __int64 v4; // x20
  __int64 v5; // x23
  __int64 v6; // x8
  _QWORD *v7; // x8
  unsigned int v8; // w9
  __int64 v9; // x10
  __int64 random_u32; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x24
  __int64 result; // x0
  __int64 v14; // x19
  unsigned int v15; // w20

  v2 = *a2;
  v4 = *(_QWORD *)(a1 + 48);
  v5 = *(_QWORD *)(a1 + 16);
  if ( *((_DWORD *)a2 + 4) == 1 )
  {
    v6 = *(_QWORD *)(v5 + 192);
    if ( !v6 )
      goto LABEL_9;
  }
  else
  {
    v7 = (_QWORD *)a2[1];
    v8 = 0;
    do
    {
      ++v8;
      *v7 = *(_QWORD *)(v2 + 16);
      v9 = *(_QWORD *)(v2 + 24);
      v2 += 32;
      v7[1] = v9;
      v7 += 2;
    }
    while ( v8 < *((_DWORD *)a2 + 4) - 1 );
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( !v6 )
      goto LABEL_9;
  }
  if ( !*(_DWORD *)(v6 + 24) )
    ipc_log_string(*(_QWORD *)(v6 + 32), "[D][%s] BHIe programming for RDDM\n", "mhi_rddm_prepare");
LABEL_9:
  mhi_write_reg(a1, v4, 100, *(unsigned int *)(v2 + 20));
  mhi_write_reg(a1, v4, 96, *(unsigned int *)(v2 + 16));
  random_u32 = mhi_write_reg(a1, v4, 104, *(unsigned int *)(v2 + 24));
  do
  {
    random_u32 = get_random_u32(random_u32);
    v11 = 0x3FFFFFFFLL * (unsigned int)random_u32;
  }
  while ( (v11 & 0xFFFFFFFC) == 0 );
  v12 = HIDWORD(v11);
  result = mhi_write_reg_field(a1, v4, 112, 0x3FFFFFFF, (unsigned int)(HIDWORD(v11) + 1));
  v14 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( (_DWORD)result )
  {
    v15 = result;
    dev_err(v5 + 40, "[E][%s] Failed to write sequence ID for BHIE_RXVECDB\n", "mhi_rddm_prepare");
    result = v15;
    if ( v14 && *(_DWORD *)(v14 + 24) <= 2u )
    {
      ipc_log_string(
        *(_QWORD *)(v14 + 32),
        "[E][%s] Failed to write sequence ID for BHIE_RXVECDB\n",
        "mhi_rddm_prepare");
      return v15;
    }
  }
  else if ( v14 )
  {
    if ( !*(_DWORD *)(v14 + 24) )
    {
      ipc_log_string(
        *(_QWORD *)(v14 + 32),
        "[D][%s] Address: %p and len: 0x%zx sequence: %u\n",
        "mhi_rddm_prepare",
        (const void *)(v2 + 16),
        *(_QWORD *)(v2 + 24),
        v12 + 1);
      return 0;
    }
  }
  return result;
}
