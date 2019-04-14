using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace IotServer.Controllers
{

    [Route("api/[controller]")]
    [ApiController]
    public class IoTController : ControllerBase
    {
        // GET /api/IoT/GetLog
        [HttpGet]
        [Route("GetLog")]
        public string GetLog(string ping, string pingCm)
        {
            if (string.Equals(ping, "0") == true 
                && string.Equals(pingCm, "0") == true)
            {
                return string.Empty;
            }

            var _encoding = Encoding.GetEncoding("utf-8");
            var _tick = DateTime.Now.Ticks;
            var _message = new StringBuilder();

            _message.AppendLine($"{_tick},{ping},{pingCm}");

            //記錄到文字檔案
            System.IO.File.AppendAllText("log.txt"
                                        , _message.ToString()
                                        , _encoding);

            return string.Format("{0:yyyy/MM/dd HH:mm:ss}", DateTime.Now);
        }
    }
}
