__int64 __fastcall kgsl_free_faults(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x22
  __int64 v5; // x0

  if ( (*(_BYTE *)(result + 203) & 0x40) != 0 )
  {
    v1 = *(_QWORD **)(result + 296);
    v2 = result + 296;
    if ( v1 != (_QWORD *)(result + 296) )
    {
      do
      {
        v4 = (_QWORD *)*v1;
        v3 = (_QWORD *)v1[1];
        if ( (_QWORD *)*v3 == v1 && (_QWORD *)v4[1] == v1 )
        {
          v4[1] = v3;
          *v3 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
        }
        v5 = v1[3];
        *v1 = 0xDEAD000000000100LL;
        v1[1] = 0xDEAD000000000122LL;
        kfree(v5);
        result = kfree(v1);
        v1 = v4;
      }
      while ( v4 != (_QWORD *)v2 );
    }
  }
  return result;
}
