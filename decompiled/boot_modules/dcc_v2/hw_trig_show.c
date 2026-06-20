__int64 __fastcall hw_trig_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v3 + 328) > (unsigned int)*(unsigned __int8 *)(v3 + 332) )
    return (int)scnprintf(
                  a3,
                  4096,
                  "%u\n",
                  *(unsigned __int8 *)(*(_QWORD *)(v3 + 128) + *(unsigned __int8 *)(v3 + 332)));
  dev_err(a1, "Select link list to program using curr_list\n");
  return -22;
}
