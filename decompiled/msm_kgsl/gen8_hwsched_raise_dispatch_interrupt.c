__int64 __fastcall gen8_hwsched_raise_dispatch_interrupt(__int64 result)
{
  _QWORD *v1; // x8
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x20
  _QWORD *v6; // x24

  v1 = *(_QWORD **)(result + 22768);
  v2 = result + 22768;
  if ( v1 != (_QWORD *)(result + 22768) )
  {
    v3 = result;
    do
    {
      v5 = *(v1 - 1);
      v6 = (_QWORD *)*v1;
      result = adreno_hwsched_drawobj_replay(v3, v5);
      if ( (result & 1) != 0 )
      {
        v4 = *(_QWORD *)(v5 + 8);
        if ( (*(_QWORD *)(v3 + 14240) & 0x200) != 0 )
        {
          if ( v4 && (*(_BYTE *)(v4 + 203) & 0x20) != 0 )
          {
            LOBYTE(v4) = 4;
          }
          else
          {
            LODWORD(v4) = *(_DWORD *)(v4 + 8) >> 2;
            if ( (unsigned int)v4 >= 3 )
              LOBYTE(v4) = 3;
          }
        }
        else if ( v4 )
        {
          LODWORD(v4) = (*(_DWORD *)(v4 + 200) >> 29) & 1;
        }
        result = gmu_core_regwrite(v3, 129428, (unsigned int)(4 << v4));
      }
      v1 = v6;
    }
    while ( v6 != (_QWORD *)v2 );
  }
  return result;
}
