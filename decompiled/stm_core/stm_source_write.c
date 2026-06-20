__int64 __fastcall stm_source_write(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x24
  unsigned int v5; // w8
  unsigned int lock; // w0
  __int64 v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x9
  unsigned int v14; // w0
  unsigned int v15; // w20

  v4 = *(_QWORD *)(a1 + 8);
  v5 = *(_DWORD *)(v4 + 964);
  if ( v5 )
  {
    if ( v5 <= a2 )
    {
      return (unsigned int)-22;
    }
    else
    {
      lock = _srcu_read_lock(&stm_source_srcu);
      v11 = *(_QWORD *)(v4 + 928);
      v12 = lock;
      if ( v11 )
      {
        v13 = *(_QWORD *)(v11 + 1064);
        if ( v13 )
        {
          v14 = (*(__int64 (__fastcall **)(_QWORD, __int64, _QWORD, __int64, __int64, __int64))(v13 + 16))(
                  *(_QWORD *)(v11 + 984),
                  v4 + 952,
                  a2,
                  a3,
                  a4,
                  a1);
          if ( (v14 & 0x80000000) != 0 )
            v15 = v14;
          else
            v15 = v14 & 0x7FFFFFFF;
        }
        else
        {
          v15 = -19;
        }
      }
      else
      {
        v15 = -19;
      }
      _srcu_read_unlock(&stm_source_srcu, v12);
    }
  }
  else
  {
    return (unsigned int)-19;
  }
  return v15;
}
