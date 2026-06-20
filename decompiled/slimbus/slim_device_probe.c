__int64 __fastcall slim_device_probe(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  __int64 v4; // x8
  void (__fastcall *v5)(__int64, __int64); // x8

  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 136) - 32LL);
  if ( *((_DWORD *)v2 - 1) != -104184290 )
    __break(0x8228u);
  result = v2();
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(a1 + 933) & 1) == 0 && (unsigned int)slim_device_alloc_laddr(a1, 0) )
    {
      dev_err(a1, "Failed to get logical address\n");
      return 4294966779LL;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 928) != 1 )
      {
        v4 = *(_QWORD *)(a1 + 136);
        *(_DWORD *)(a1 + 928) = 1;
        if ( v4 )
        {
          v5 = *(void (__fastcall **)(__int64, __int64))(v4 - 8);
          if ( v5 )
          {
            if ( *((_DWORD *)v5 - 1) != -1055034444 )
              __break(0x8228u);
            v5(a1, 1);
          }
        }
      }
      return 0;
    }
  }
  return result;
}
