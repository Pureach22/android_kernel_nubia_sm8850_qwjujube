__int64 *__fastcall sde_encoder_phys_cmd_update_flush_mask(__int64 *result)
{
  __int64 *v1; // x19
  __int64 v2; // x20
  unsigned int v3; // w21
  __int64 (__fastcall *v4)(__int64, __int64, __int64, __int64); // x8
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  __int64 v9; // x2
  int v10; // w4

  if ( result[53] )
  {
    v1 = result;
    if ( result[62] )
    {
      result = (__int64 *)sde_encoder_get_disp_op(*result);
      v2 = v1[52];
      if ( v2 )
      {
        v3 = (unsigned int)result;
        if ( (unsigned int)result >= 3 )
        {
          __break(0x5512u);
          JUMPOUT(0xFF65C);
        }
        v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v2 + 1192 + 8LL * (unsigned int)result);
        if ( v4 )
        {
          v5 = *((unsigned int *)v1 + 168);
          v6 = v1[52];
          if ( *((_DWORD *)v4 - 1) != 949740941 )
            __break(0x8228u);
          result = (__int64 *)v4(v6, 7, v5, 1);
        }
        v7 = *(_QWORD *)(v1[62] + 56);
        if ( v7 )
        {
          v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v2 + 1192 + 8LL * v3);
          if ( v8 )
          {
            v9 = *(unsigned int *)(v7 + 32);
            if ( *((_DWORD *)v8 - 1) != 949740941 )
              __break(0x8228u);
            result = (__int64 *)v8(v2, 3, v9, 1);
          }
        }
        if ( (_drm_debug & 4) != 0 )
        {
          if ( *v1 )
            v10 = *(_DWORD *)(*v1 + 24);
          else
            v10 = -1;
          return (__int64 *)_drm_dev_dbg(
                              0,
                              0,
                              0,
                              "enc%d intf%d update pending flush ctl %d intf_idx %x\n",
                              v10,
                              *((_DWORD *)v1 + 168) - 1,
                              *(_DWORD *)(v2 + 64) - 1,
                              *((_DWORD *)v1 + 168));
        }
      }
    }
  }
  return result;
}
