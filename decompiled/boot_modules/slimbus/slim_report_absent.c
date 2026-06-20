__int64 __fastcall slim_report_absent(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x8
  _DWORD *v4; // x8

  v1 = *(_QWORD *)(result + 920);
  if ( v1 )
  {
    v2 = result;
    mutex_lock(v1 + 80);
    *(_BYTE *)(v2 + 933) = 0;
    result = mutex_unlock(v1 + 80);
    if ( !*(_QWORD *)(v1 + 280) )
      result = ida_free(v1 + 56, *(unsigned __int8 *)(v2 + 932));
    if ( *(_DWORD *)(v2 + 928) )
    {
      v3 = *(_QWORD *)(v2 + 136);
      *(_DWORD *)(v2 + 928) = 0;
      if ( v3 )
      {
        v4 = *(_DWORD **)(v3 - 8);
        if ( v4 )
        {
          if ( *(v4 - 1) != -1055034444 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _QWORD))v4)(v2, 0);
        }
      }
    }
  }
  return result;
}
