__int64 __fastcall rmnet_descriptor_deinit(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x0
  _QWORD *v4; // x21

  v1 = *(_QWORD *)(result + 2808);
  if ( v1 )
  {
    v2 = result;
    v3 = *(_QWORD **)v1;
    if ( *(_QWORD *)v1 != v1 )
    {
      do
      {
        v4 = (_QWORD *)*v3;
        kfree(v3);
        v3 = v4;
        --*(_DWORD *)(v1 + 16);
      }
      while ( v4 != (_QWORD *)v1 );
    }
    result = kfree(v1);
    *(_QWORD *)(v2 + 2808) = 0;
  }
  return result;
}
