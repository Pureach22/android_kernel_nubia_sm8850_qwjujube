__int64 __fastcall crc_error_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned int v6; // w8
  int v7; // w9
  int v8; // w11
  unsigned int v9; // w8
  int v10; // w9
  __int64 v11; // x19

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 24);
  v6 = *(unsigned __int8 *)(v3 + 332);
  if ( *(_DWORD *)(v3 + 328) <= v6 )
  {
    dev_err(a1, "Select link list to program using curr_list\n");
    goto LABEL_9;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v3 + 120) + *(unsigned __int8 *)(v3 + 332)) != 1 )
  {
LABEL_9:
    v11 = -22;
    goto LABEL_10;
  }
  v7 = v6 << 7;
  v8 = *(_DWORD *)(v3 + 104);
  v9 = (v6 << 7) | 0x34;
  v10 = v7 | 0x48;
  if ( v8 )
    v9 = (*(unsigned __int8 *)(v3 + 332) << 7) | 0x50;
  if ( v8 == 1 )
    v9 = v10;
  v11 = (int)scnprintf(a3, 4096, "%u\n", (*(_DWORD *)(*(_QWORD *)v3 + v9) >> 1) & 1);
LABEL_10:
  mutex_unlock(v3 + 24);
  return v11;
}
