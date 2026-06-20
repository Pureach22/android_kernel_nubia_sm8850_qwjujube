__int64 __fastcall ready_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v6; // x8
  __int64 v7; // x19

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 24);
  if ( *(_DWORD *)(v3 + 328) <= (unsigned int)*(unsigned __int8 *)(v3 + 332) )
  {
    dev_err(a1, "Select link list to program using curr_list\n");
    goto LABEL_7;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v3 + 120) + *(unsigned __int8 *)(v3 + 332)) != 1 )
  {
LABEL_7:
    v7 = -22;
    goto LABEL_8;
  }
  v6 = 28;
  if ( !*(_DWORD *)(v3 + 104) )
    v6 = 12;
  v7 = (int)scnprintf(a3, 4096, "%u\n", (*(_DWORD *)(*(_QWORD *)v3 + v6) >> 1) & 1);
LABEL_8:
  mutex_unlock(v3 + 24);
  return v7;
}
