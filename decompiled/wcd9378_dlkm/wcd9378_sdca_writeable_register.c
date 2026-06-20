__int64 __fastcall wcd9378_sdca_writeable_register(unsigned int a1)
{
  if ( a1 >> 30 )
    return ((unsigned __int8)wcd9378_reg_access[a1 & 0xFFF | ((unsigned __int8)(a1 >> 20) << 12)] >> 1) & 1;
  else
    return 0;
}
