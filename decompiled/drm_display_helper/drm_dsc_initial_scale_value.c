__int64 __fastcall drm_dsc_initial_scale_value(__int64 a1)
{
  return (unsigned int)(8
                      * *(unsigned __int16 *)(a1 + 104)
                      / (*(unsigned __int16 *)(a1 + 104) - *(unsigned __int16 *)(a1 + 28)));
}
