__int64 __fastcall sde_connector_commit_reset(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 hw_ctl; // x0
  __int64 v5; // x3

  if ( !result )
    return printk(&unk_242658, "sde_connector_commit_reset");
  if ( (*(_BYTE *)(result + 5129) & 1) == 0 )
  {
    if ( *(_DWORD *)(result + 2736) == 15 )
    {
      v2 = result;
      v3 = a2;
      hw_ctl = sde_encoder_get_hw_ctl(result);
      a2 = v3;
      v5 = hw_ctl;
      result = v2;
    }
    else
    {
      v5 = 0;
    }
    return sde_fence_signal(*(_QWORD *)(result + 2864), a2, 1, v5);
  }
  return result;
}
