__int64 __fastcall sde_plane_halt_requests(__int64 a1, char a2)
{
  __int64 v2; // x8
  char v4; // w20
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x0
  int v9; // w8
  int v10; // w9
  char v11; // w10
  __int64 result; // x0
  void *v13; // x0
  char v14; // [xsp+0h] [xbp-20h]
  _DWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF
  char v16; // [xsp+14h] [xbp-Ch]
  char v17; // [xsp+15h] [xbp-Bh]
  __int16 v18; // [xsp+16h] [xbp-Ah]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 2208);
    if ( v2 && *(_QWORD *)(v2 + 56) )
    {
      v4 = a2 & 1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_plane_halt_requests",
        1952,
        -1,
        *(_DWORD *)(a1 + 104),
        *(unsigned __int8 *)(a1 + 2417),
        a2 & 1,
        -1059143953,
        v14);
      if ( *(_QWORD *)a1 )
      {
        v5 = *(_QWORD *)(a1 + 2208);
        if ( v5 && (v6 = *(_QWORD *)(v5 + 56)) != 0 )
        {
          v7 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
          if ( v7 )
          {
            v8 = *(_QWORD *)(v7 + 8);
            if ( v8 )
            {
              v10 = *(_DWORD *)(v6 + 56);
              v9 = *(_DWORD *)(v6 + 60);
              v11 = *(_BYTE *)(a1 + 2417);
              v15[0] = 0;
              v18 = 0;
              v17 = v4;
              v15[1] = v10;
              v15[2] = v9;
              v16 = v11;
              result = ((__int64 (__fastcall *)(__int64, _DWORD *))sde_vbif_set_xin_halt)(v8, v15);
LABEL_16:
              *(_BYTE *)(a1 + 2417) = result & 1;
              goto LABEL_17;
            }
          }
          v13 = &unk_25EA03;
        }
        else
        {
          v13 = &unk_262833;
        }
      }
      else
      {
        v13 = &unk_26FEB0;
      }
      printk(v13, "_sde_plane_halt_requests");
      result = 0;
      goto LABEL_16;
    }
    result = printk(&unk_262833, "sde_plane_halt_requests");
  }
  else
  {
    result = printk(&unk_226FC0, "sde_plane_halt_requests");
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
