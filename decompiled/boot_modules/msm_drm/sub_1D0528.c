// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_1D0528@<X0>(__int64 a1@<X5>, void (*a2)(void)@<X8>)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 v4; // x0
  void (*v5)(void); // x8
  int v6; // w8
  _QWORD *v7; // x9
  __int64 v8; // x0
  void (*v9)(void); // x8
  int v10; // w8
  int v11; // w16
  int v12; // w17
  __int64 v13; // x19
  __int64 v14; // x20
  __int64 v15; // x21
  __int64 v16; // x22
  __int64 v17; // x23

  if ( a1 )
    return dsi_ctrl_hw_22_configure_cmddma_window();
LABEL_8:
  if ( v11 != v12 )
    __break(0x8228u);
  a2();
  v3 = *(_DWORD *)(v13 + 196);
  *(_QWORD *)(v17 - 32) = 0;
  *(_QWORD *)(v16 + v14 - 64) = 0;
  *(_DWORD *)(v13 + 196) = v3 - 1;
  while ( 1 )
  {
    v4 = *(_QWORD *)(v16 + v14);
    if ( v4 )
    {
      v5 = *(void (**)(void))(v4 + 88);
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != -511414616 )
          __break(0x8228u);
        v5();
        v6 = *(_DWORD *)(v13 + 196);
        v7 = (_QWORD *)(v16 + v14);
        *v7 = 0;
        *(v7 - 8) = 0;
        *(_DWORD *)(v13 + 196) = v6 - 1;
      }
    }
    v8 = *(_QWORD *)(v16 + v14 - 64);
    if ( v8 )
    {
      v9 = *(void (**)(void))(v8 + 88);
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -511414616 )
          __break(0x8228u);
        v9();
        v10 = *(_DWORD *)(v13 + 196);
        *(_QWORD *)(v16 + v14 - 64) = 0;
        *(_DWORD *)(v13 + 196) = v10 - 1;
      }
    }
    v14 += 8;
    if ( v15 == v14 )
      break;
    if ( v14 == 32 )
    {
      __break(0x5512u);
      JUMPOUT(0xDA200);
    }
    v17 = v16 + v14;
    v2 = *(_QWORD *)(v16 + v14 - 32);
    if ( v2 )
    {
      a2 = *(void (**)(void))(v2 + 88);
      if ( a2 )
      {
        v11 = *((_DWORD *)a2 - 1);
        v12 = -511414616;
        goto LABEL_8;
      }
    }
  }
  if ( *(_DWORD *)(v13 + 196) )
    printk(&unk_245FD4, "sde_encoder_destroy");
  *(_DWORD *)(v13 + 196) = 0;
  mutex_unlock(v13 + 528);
  ((void (__fastcall *)(__int64))drm_encoder_cleanup)(v13);
  kfree(*(_QWORD *)(v13 + 1304));
  *(_QWORD *)(v13 + 1304) = 0;
  return kfree(v13);
}
