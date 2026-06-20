__int64 __fastcall sde_encoder_get_qsync_fps_callback(__int64 result, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x8
  _DWORD *v6; // x19

  if ( a2 )
  {
    *a2 = 0;
    if ( result )
    {
      v4 = *(_QWORD *)(result + 328);
      if ( a4 | v4 )
      {
        if ( !a4 )
        {
          a4 = *(_QWORD *)(v4 + 8);
          if ( !a4 )
            goto LABEL_11;
        }
        v5 = *(__int64 (__fastcall **)(_QWORD))(a4 + 3184);
        if ( v5 )
        {
          v6 = a2;
          if ( *((_DWORD *)v5 - 1) != 1917458973 )
            __break(0x8228u);
          result = v5(a3);
          LODWORD(a4) = result;
          if ( (result & 0x80000000) == 0 )
          {
            a2 = v6;
LABEL_11:
            *a2 = a4;
            return result;
          }
          return printk(&unk_26211F, "_sde_encoder_get_qsync_fps_callback");
        }
        else
        {
          *a2 = 0;
        }
      }
      else
      {
        return printk(&unk_273944, "_sde_encoder_get_qsync_fps_callback");
      }
    }
    else
    {
      return printk(&unk_246014, "_sde_encoder_get_qsync_fps_callback");
    }
  }
  return result;
}
