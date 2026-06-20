__int64 __fastcall cam_req_mgr_notify_message(__int64 *a1, __int64 a2, int a3)
{
  int v4; // w21
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // [xsp+0h] [xbp-90h] BYREF
  __int64 v14; // [xsp+8h] [xbp-88h]
  __int64 v15; // [xsp+10h] [xbp-80h]
  __int64 v16; // [xsp+18h] [xbp-78h]
  __int64 v17; // [xsp+20h] [xbp-70h]
  __int64 v18; // [xsp+28h] [xbp-68h]
  __int64 v19; // [xsp+30h] [xbp-60h]
  __int64 v20; // [xsp+38h] [xbp-58h]
  __int64 v21; // [xsp+40h] [xbp-50h]
  __int64 v22; // [xsp+48h] [xbp-48h]
  __int64 v23; // [xsp+50h] [xbp-40h]
  __int64 v24; // [xsp+58h] [xbp-38h]
  __int64 v25; // [xsp+60h] [xbp-30h]
  __int64 v26; // [xsp+68h] [xbp-28h]
  __int64 v27; // [xsp+70h] [xbp-20h]
  __int64 v28; // [xsp+78h] [xbp-18h]
  __int64 v29; // [xsp+80h] [xbp-10h]
  __int64 v30; // [xsp+88h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v4 = a2;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 0;
    if ( (_DWORD)a2 == 1 )
    {
      v6 = 20;
    }
    else
    {
      if ( (_DWORD)a2 != 6 )
      {
LABEL_8:
        v8 = a1[4];
        v9 = a1[5];
        LODWORD(v25) = v4;
        LODWORD(v13) = a3;
        v18 = v8;
        v19 = v9;
        v10 = a1[7];
        v20 = a1[6];
        v21 = v10;
        v11 = a1[1];
        v14 = *a1;
        v15 = v11;
        v12 = a1[3];
        v16 = a1[2];
        v17 = v12;
        v4l2_event_queue(g_dev, &v13);
        result = 0;
        goto LABEL_9;
      }
      v6 = 12;
    }
    cam_req_mgr_dump_linked_devices_on_err(*(unsigned int *)((char *)a1 + v6), a2);
    goto LABEL_8;
  }
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
