__int64 __fastcall kgsl_unmap_and_put_gpuaddr(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8

  if ( *(_QWORD *)(result + 40) )
  {
    v1 = (_QWORD *)result;
    if ( *(_QWORD *)(result + 24) )
    {
      if ( result )
      {
        if ( (*(_DWORD *)(result + 48) & 2) != 0 )
        {
          __break(0x800u);
          return result;
        }
        if ( (*(_DWORD *)(result + 48) & 0x800) != 0 )
          goto LABEL_18;
      }
      result = kgsl_mmu_unmap(*(_QWORD *)result, result);
      if ( !(_DWORD)result )
      {
LABEL_18:
        if ( *v1 )
        {
          v2 = *(_QWORD *)(*v1 + 96LL);
          if ( v2 )
          {
            v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 80);
            if ( v3 )
            {
              if ( *((_DWORD *)v3 - 1) != 1555154090 )
                __break(0x8228u);
              result = v3(v1);
            }
          }
        }
        v1[3] = 0;
        *v1 = 0;
      }
    }
  }
  return result;
}
